/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e260; label: FUN_0059e260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059e260(int param_1)

{
  int iVar1;
  short sVar2;
  
  DAT_0095642c = 0;
  DAT_00956430 = 0;
  FUN_004f10e0(param_1,&PTR_s_Parent_00805600);
  iVar1 = FUN_004fc5b0(param_1);
  while (iVar1 != 0) {
    FUN_004f7fb0(param_1);
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_0075ff74);
    if (iVar1 == 0) break;
    FUN_004fa020(param_1);
    iVar1 = FUN_004fc5b0(param_1);
  }
  FUN_004f11e0(param_1);
  iVar1 = DAT_009562f8;
  sVar2 = -1 - (short)DAT_0095634c;
  *(short *)(DAT_009562f8 + (DAT_0095634c * 0x38 + DAT_0095642c) * 2) = sVar2;
  *(short *)(iVar1 + 0x20 + (DAT_0095634c * 0x38 + DAT_00956430) * 2) = sVar2;
  DAT_0095634c = DAT_0095634c + 1;
  return;
}

