/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69ef50; label: FUN_0069ef50
 */

void FUN_0069ef50(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    *(undefined1 *)(*param_1 + 0x16) = 0;
    *(undefined1 *)(*param_1 + 0x17) = 0;
    *(undefined1 *)(*param_1 + 0x18) = 0;
    *(undefined1 *)(*param_1 + 0x19) = 0;
    uVar1 = 0;
    if (0 < param_1[1]) {
      do {
        uVar1 = uVar1 << 8 ^
                *(uint *)(&DAT_0076f038 + ((uint)*(byte *)(*param_1 + iVar2) ^ uVar1 >> 0x18) * 4);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[1]);
    }
    iVar2 = 0;
    if (0 < param_1[3]) {
      do {
        uVar1 = uVar1 << 8 ^
                *(uint *)(&DAT_0076f038 + ((uint)*(byte *)(param_1[2] + iVar2) ^ uVar1 >> 0x18) * 4)
        ;
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[3]);
    }
    *(char *)(*param_1 + 0x16) = (char)uVar1;
    *(char *)(*param_1 + 0x17) = (char)(uVar1 >> 8);
    *(char *)(*param_1 + 0x18) = (char)(uVar1 >> 0x10);
    *(char *)(*param_1 + 0x19) = (char)(uVar1 >> 0x18);
  }
  return;
}

