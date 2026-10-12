/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x6886a0; label: FUN_006886a0
 */

void FUN_006886a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  DAT_029620f4 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_0065ada0,"Sound Type");
  if (DAT_029620f4 != 0) {
    uVar1 = FUN_00627b80(99999,&local_10,DAT_02924afc == -1,0,&LAB_0065a700,&DAT_007600a0);
    FUN_00618e10(DAT_029620f4,uVar1);
    iVar2 = 0;
    if (0 < DAT_02947b38) {
      do {
        bVar3 = DAT_02924afc == iVar2;
        uVar1 = FUN_00627b80(iVar2,&local_10,bVar3,1,&LAB_0065a700,0);
        FUN_00618e10(DAT_029620f4,uVar1);
        if (bVar3) {
          *(undefined4 *)(DAT_029620f4 + 8) = DAT_02900c84;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_02947b38);
    }
    FUN_006279b0(param_1,DAT_029620f4);
    *(int *)(DAT_029620f4 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029620f4 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

