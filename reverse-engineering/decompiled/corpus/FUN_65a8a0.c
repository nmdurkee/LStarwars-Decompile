/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x65a8a0; label: FUN_0065a8a0
 */

void FUN_0065a8a0(int param_1)

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
  DAT_029620dc = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_0065a880,"Particle Type");
  if (DAT_029620dc != 0) {
    uVar1 = FUN_00627b80(0,&local_10,DAT_02924ac8 == -1,0,&LAB_0065a790,&DAT_007600a0);
    FUN_00618e10(DAT_029620dc,uVar1);
    iVar2 = 1;
    if (1 < DAT_02962098) {
      do {
        if (*(int *)(DAT_0296209c + iVar2 * 4) != 0) {
          bVar3 = DAT_02924ac8 == iVar2;
          uVar1 = FUN_00627b80(iVar2,&local_10,bVar3,1,&LAB_0065a790,
                               *(undefined4 *)(DAT_0296209c + iVar2 * 4));
          FUN_00618e10(DAT_029620dc,uVar1);
          if (bVar3) {
            *(undefined4 *)(DAT_029620dc + 8) = DAT_02900c84;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_02962098);
    }
    FUN_006279b0(param_1,DAT_029620dc);
    *(int *)(DAT_029620dc + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029620dc + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

