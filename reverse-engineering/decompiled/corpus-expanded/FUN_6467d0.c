/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x6467d0; label: FUN_006467d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006467d0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_02920a1c = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_006467b0,"Sound Control");
    if (DAT_02920a1c != 0) {
      uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) << 0x10,&DAT_008109d8,
                           *(char *)(*(int *)(param_2 + 0xc) + 0x158 + DAT_02920970) == '\0',1,
                           FUN_006465a0,&DAT_0076b29c);
      FUN_00618e10(DAT_02920a1c,uVar1);
      if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
        *(int *)(DAT_02920a1c + 8) = DAT_02900c84;
      }
      uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 1,&DAT_008109d8,
                           *(char *)(*(int *)(param_2 + 0xc) + 0x158 + DAT_02920970) == '\x01',1,
                           FUN_006465a0,"On Edge");
      FUN_00618e10(DAT_02920a1c,uVar1);
      if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
        *(int *)(DAT_02920a1c + 8) = DAT_02900c84;
      }
      uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 2,&DAT_008109d8,
                           *(char *)(*(int *)(param_2 + 0xc) + 0x158 + DAT_02920970) == '\x02',1,
                           FUN_006465a0,"Off Edge");
      FUN_00618e10(DAT_02920a1c,uVar1);
      if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
        *(int *)(DAT_02920a1c + 8) = DAT_02900c84;
      }
      uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 3,&DAT_008109d8,
                           *(char *)(*(int *)(param_2 + 0xc) + 0x158 + DAT_02920970) == '\x03',1,
                           FUN_006465a0,"Per PART");
      FUN_00618e10(DAT_02920a1c,uVar1);
      if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
        *(int *)(DAT_02920a1c + 8) = DAT_02900c84;
      }
      uVar1 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 4,&DAT_008109d8,
                           *(char *)(*(int *)(param_2 + 0xc) + 0x158 + DAT_02920970) == '\x04',1,
                           FUN_006465a0,"Continuous");
      FUN_00618e10(DAT_02920a1c,uVar1);
      if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
        *(int *)(DAT_02920a1c + 8) = DAT_02900c84;
      }
      FUN_006279b0(param_1,DAT_02920a1c);
      *(int *)(DAT_02920a1c + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02920a1c + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

