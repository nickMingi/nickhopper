package google;

import java.util.ArrayList;
import java.util.List;

public class WordCompletion {

	static class TrieNode{
		char letter;
		TrieNode previousLetter;
		TrieNode[] nextLetters;
		int frequency;
		boolean isEndOfWord;
		
		public TrieNode(char letter, TrieNode previousLetter){
			this.letter = letter;
			this.previousLetter = previousLetter;
		}
	}
	
	static class Trie{
		private TrieNode root;
		
		class WordFrequency{ // keeps track of the frequency to rank the words
			String word;
			int frequency;
			
			WordFrequency(String w, int f){
				word = w;
				frequency = f;
			}
		}
		
		public Trie(int sizeCharSet){
			root = new TrieNode('&', null);
			root.nextLetters = new TrieNode[sizeCharSet]; //
		}
		
		public boolean insert(String word){ // if the word is new return true, else false;
			TrieNode current = root;
			current.frequency++; 			// root.frequency stores how many words in total are in the Trie 
			for(int i = 0; i < word.length(); i++){
				int letter = word.charAt(i) - 'a';
				if(current.nextLetters[letter] == null){
					current.nextLetters[letter] = new TrieNode(word.charAt(i), current);
				}
				current.nextLetters[letter].frequency++;
				
				current = current.nextLetters[letter];
			}
			
			if(current.isEndOfWord){
				return false;
			}else{
				return true;
			}
		}
		
		public List<WordFrequency> search(String prefix){ // returns a list of words with the given prefix
			List<WordFrequency> autoCompletion = new ArrayList<>();
			
			TrieNode current = root;
			
			for(char c : prefix.toCharArray()){
				if(current.nextLetters[c = 'a'] == null){
					return autoCompletion;
				}else{
					current = current.nextLetters[c - 'a'];
				}
			}
			
			List<WordFrequency> surfix = new ArrayList<>();
			depthFirstSearch(current, surfix, new StringBuilder());
			
			for(WordFrequency wf : surfix){
				wf.word = prefix + wf.word;
				autoCompletion.add(wf);
			}
			
			// You may rank the autoCompletion by frequency according to the requirment in the follow-up question
			return autoCompletion;
		}
		
		private void depthFirstSearch(TrieNode current, List<WordFrequency> surfix, StringBuilder str){
			if(current == null) return;
			
			str.append(current.letter);
			
			if(current.isEndOfWord && str.length() > 0) surfix.add(new WordFrequency(str.toString(), current.frequency));
			
			for(TrieNode nextLetter : current.nextLetters){
				depthFirstSearch(nextLetter, surfix, str);
			}
			str.deleteCharAt(str.length() - 1);
		}
	}
}
