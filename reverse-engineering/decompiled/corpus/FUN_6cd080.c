/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cd080; label: FUN_006cd080
 */

void FUN_006cd080(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uVar4;
  
  puVar3 = *(undefined4 **)(in_ECX + 0xc);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = FUN_0061f030();
    if (puVar3[2] != iVar1) {
      puVar3 = (undefined4 *)FUN_006c5c10(*puVar3);
    }
    if (puVar3 != (undefined4 *)0x0) {
      if (puVar3 != *(undefined4 **)(in_ECX + 0x10)) {
        puVar3 = *(undefined4 **)(in_ECX + 0xc);
        uVar4 = 0;
        if (puVar3 != (undefined4 *)0x0) {
          iVar1 = FUN_0061f030();
          if (puVar3[2] != iVar1) {
            puVar3 = (undefined4 *)FUN_006c5c10(*puVar3);
          }
          if (puVar3 != (undefined4 *)0x0) {
            uVar4 = *puVar3;
          }
        }
        FUN_006c5c80(uVar4);
        return;
      }
      FUN_006271a0(0);
      return;
    }
  }
  iVar2 = FUN_0061f000();
  iVar1 = DAT_02973a7c;
  if (((iVar2 == 0) || (iVar1 = DAT_02973a80, iVar2 == DAT_02973a7c)) && (iVar1 != 0)) {
    return;
  }
  FUN_006c5c80(*(undefined4 *)(in_ECX + 0xc));
  return;
}

