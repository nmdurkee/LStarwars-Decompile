/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x65ee90; label: FUN_0065ee90
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065ee90(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < DAT_02962a08) {
    iVar2 = 0;
    do {
      *(undefined4 *)(iVar2 + 4 + DAT_02962a14) = 0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x50;
    } while (iVar1 < DAT_02962a08);
  }
  iVar1 = 0;
  DAT_02920acc = 0;
  _DAT_02961f54 = 0;
  DAT_029211a8 = 0;
  DAT_02920ad0 = 0;
  DAT_02961f58 = 0;
  DAT_029211ac = 0;
  _DAT_02920ad4 = 0;
  _DAT_02961f5c = 0;
  _DAT_029211b0 = 0;
  _DAT_02920ad8 = 0;
  _DAT_02961f60 = 0;
  _DAT_029211b4 = 0;
  _DAT_02920adc = 0;
  _DAT_02961f64 = 0;
  _DAT_029211b8 = 0;
  _DAT_02920ae0 = 0;
  _DAT_02961f68 = 0;
  _DAT_029211bc = 0;
  _DAT_02920ae4 = 0;
  _DAT_02961f6c = 0;
  _DAT_029211c0 = 0;
  _DAT_02920ae8 = 0;
  _DAT_02961f70 = 0;
  _DAT_029211c4 = 0;
  DAT_029629e0 = 0;
  if (0 < DAT_02962a0c) {
    do {
      *(undefined4 *)(DAT_02962a1c + iVar1 * 4) = 0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_02962a0c);
  }
  DAT_02962a20 = 0;
  return;
}

