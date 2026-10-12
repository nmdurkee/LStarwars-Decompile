/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x6651e0; label: FUN_006651e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006651e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    *(undefined4 *)(iVar1 + 0x2b0) = *(undefined4 *)(iVar1 + 0x150);
    *(float *)(iVar1 + 0x2b4) = *(float *)(iVar1 + 0x154) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2b8) = *(undefined4 *)(iVar1 + 0x158);
    *(float *)(iVar1 + 700) = *(float *)(iVar1 + 0x15c) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2c0) = *(undefined4 *)(iVar1 + 0x160);
    *(float *)(iVar1 + 0x2c4) = *(float *)(iVar1 + 0x164) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2c8) = *(undefined4 *)(iVar1 + 0x168);
    *(float *)(iVar1 + 0x2cc) = *(float *)(iVar1 + 0x16c) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2d0) = *(undefined4 *)(iVar1 + 0x170);
    *(float *)(iVar1 + 0x2d4) = *(float *)(iVar1 + 0x174) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2d8) = *(undefined4 *)(iVar1 + 0x178);
    *(float *)(iVar1 + 0x2dc) = *(float *)(iVar1 + 0x17c) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2e0) = *(undefined4 *)(iVar1 + 0x180);
    *(float *)(iVar1 + 0x2e4) = *(float *)(iVar1 + 0x184) / 10000.0;
    *(undefined4 *)(iVar1 + 0x2e8) = *(undefined4 *)(iVar1 + 0x188);
    *(float *)(iVar1 + 0x2ec) = *(float *)(iVar1 + 0x18c) / 10000.0;
  }
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar1;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

