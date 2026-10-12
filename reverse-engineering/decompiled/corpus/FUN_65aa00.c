/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65aa00; label: FUN_0065aa00
 */

void FUN_0065aa00(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  DAT_029620e0 = FUN_00619250(0x46,0x46,0xfa,200,DAT_02912e80,&LAB_0065a9e0,
                              "Highlighted Particle Type");
  if (DAT_029620e0 != 0) {
    iVar3 = 1;
    if (1 < DAT_02962098) {
      do {
        if (*(int *)(DAT_0296209c + iVar3 * 4) != 0) {
          iVar1 = (&DAT_0292feb4)[DAT_02962010 * 0xb5 + DAT_0292fd08];
          uVar2 = FUN_00627b80(iVar3,&local_10,iVar1 == iVar3,1,&LAB_0065a7d0,
                               *(undefined4 *)(DAT_0296209c + iVar3 * 4));
          FUN_00618e10(DAT_029620e0,uVar2);
          if (iVar1 == iVar3) {
            *(undefined4 *)(DAT_029620e0 + 8) = DAT_02900c84;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_02962098);
    }
    FUN_006279b0(param_1,DAT_029620e0);
    *(int *)(DAT_029620e0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029620e0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

