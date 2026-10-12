/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x6659d0; label: FUN_006659d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006659d0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  iVar1 = *(int *)(DAT_0296209c +
                  *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) *
                  4);
  DAT_02962a60 = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_006659b0,"Sound Control");
  if (DAT_02962a60 != 0) {
    uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) << 0x10,&local_10,
                         *(int *)(iVar1 + (*(int *)(param_2 + 0xc) * 3 + 0xf9) * 4) == 0,1,
                         FUN_006655f0,&DAT_0076b29c);
    FUN_00618e10(DAT_02962a60,uVar2);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_02962a60 + 8) = DAT_02900c84;
    }
    uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 1,&local_10,
                         *(int *)(iVar1 + (*(int *)(param_2 + 0xc) * 3 + 0xf9) * 4) == 1,1,
                         FUN_006655f0,"On Edge");
    FUN_00618e10(DAT_02962a60,uVar2);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_02962a60 + 8) = DAT_02900c84;
    }
    uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 2,&local_10,
                         *(int *)(iVar1 + (*(int *)(param_2 + 0xc) * 3 + 0xf9) * 4) == 2,1,
                         FUN_006655f0,"Off Edge");
    FUN_00618e10(DAT_02962a60,uVar2);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_02962a60 + 8) = DAT_02900c84;
    }
    uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 3,&local_10,
                         *(int *)(iVar1 + (*(int *)(param_2 + 0xc) * 3 + 0xf9) * 4) == 3,1,
                         FUN_006655f0,"Per Particle");
    FUN_00618e10(DAT_02962a60,uVar2);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_02962a60 + 8) = DAT_02900c84;
    }
    uVar2 = FUN_00627b80(*(int *)(param_2 + 0xc) * 0x10000 + 4,&local_10,
                         *(int *)(iVar1 + (*(int *)(param_2 + 0xc) * 3 + 0xf9) * 4) == 4,1,
                         FUN_006655f0,"Continuous");
    FUN_00618e10(DAT_02962a60,uVar2);
    if ((*(byte *)(DAT_02900c84 + 0x11) & 1) != 0) {
      *(int *)(DAT_02962a60 + 8) = DAT_02900c84;
    }
    FUN_006279b0(param_1,DAT_02962a60);
    *(int *)(DAT_02962a60 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_02962a60 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

