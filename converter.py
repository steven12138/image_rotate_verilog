import sys
from PIL import Image
import os

def convert_png_to_bmp(input_path, size=(256, 256)):
    # Generate the output path by changing the file extension to .bmp
    output_path = os.path.splitext(input_path)[0] + ".bmp"

    # Open the input PNG image
    with Image.open(input_path) as img:
        # Convert the image to 8-bit grayscale
        # img = img.convert("L")
        # Resize the image to 256x256
        img = img.resize(size, Image.LANCZOS)
        # Save the image as BMP
        img.save(output_path, format="BMP")

    print(f"Converted image saved to {output_path}")

# Ensure that the script is run with the correct number of arguments
if len(sys.argv) != 2:
    print("Usage: python convert.py <input_path>")
    sys.exit(1)

input_path = sys.argv[1]
convert_png_to_bmp(input_path)
