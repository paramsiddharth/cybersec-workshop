# Mysterious Files
Concealing information via embedded files.

## Execution
1. Execute `flag.py`. It asks for a flag.
2. Search for the flag inside `info.png` using
   either of the following tools:
   - Binwalk:
     ```bash
     # Look at what files are contained within
     binwalk info.png

     # The ZIP file looks interesting
     binwalk -e info.png
     cd _info.png.extracted

     # Unzip it
     unzip 134EF.zip -d folder
     cd folder

     # Look at house.txt
     cat house.txt

     # Looks like Base64
     base64 -d house.txt

     # Possible PNG
     base64 -d house.txt >house.png

     # Nice image, but there is a flag
     strings house.png | grep flag
     ```
   - Foremost:
     ```bash
     # Look at what files are contained within
     foremost info.png
     cd output

     # The ZIP file looks interesting
     cd zip

     # Unzip it
     unzip 00000154.zip -d folder
     cd folder

     # Look at house.txt
     cat house.txt

     # Looks like Base64
     base64 -d house.txt

     # Possible PNG
     base64 -d house.txt >house.png

     # Nice image, but there is a flag
     strings house.png | grep flag
     ```
   - CyberChef:
     1. Insert `info.png` inside the input.
     2. Look for embedded files.
     3. Get the ZIP file out.
     4. Extract it and grab the text file as input.
     5. Decode the Base64. Looks like a PNG.
     6. Look for strings. More specifically, the flag.
3. Enter the flag.

# Made with ❤ by [Param](https://www.paramsid.com).