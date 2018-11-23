package google;

import java.util.*;
import java.util.stream.Collectors;

public class SameUniqueCharacter {

	public static void main(String[] args) throws Exception {
        String str = "May student students dog studentssess god Cat act tab bat flow wolf lambs Amy Yam balms looped poodle john alice ";
        String[] words = str.split(" ");
        List<List<String>> repeated = getRepeatedStrings(words);
        
        System.out.println(repeated);
    }

    static List<List<String>> getRepeatedStrings(String[] words) {
        Map<String, List<String>> lookup = new HashMap<>();
        for(String current : words) {
            String key = getKey(current);
            List<String> matches = lookup.computeIfAbsent(key, o-> new ArrayList<String>());
            matches.add(current);
        }

        return lookup.values().stream().filter(list-> list.size() > 1).collect(Collectors.toList());
    }

    static int[] chars = new int[256];

    static String getKey(String s) {
        List<Character> keyChars = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            char c = Character.toLowerCase(s.charAt(i));
            if(chars[(int)c] == 0) {
                keyChars.add(c);
                chars[(int)c]++;
            }
        }

        Collections.sort(keyChars);
        StringBuilder sb = new StringBuilder();
        keyChars.forEach(c-> {
            chars[(int)c]--;
            sb.append(c);
        });
        return sb.toString();
    }
}
