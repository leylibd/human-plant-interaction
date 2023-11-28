void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}

int i = 0;

void sadFaceAnimation() {
  uint64_t image;
  memcpy_P(&image, &IMAGES[i], 8);

  displayImage(image);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }
  delay(100);
}