/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x6083d0; label: FUN_006083d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006083d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00741620((int)*(short *)(param_1 + 0x1f6));
  if (iVar1 != 0) {
    DAT_02854c20 = param_1;
    if (((*(uint *)(param_1 + 0x1f0) & 0x300000) == 0) && (*(int *)(param_1 + 0x3c) != 0)) {
      FUN_00742730(iVar1,param_1);
      FUN_00741640(iVar1);
      FUN_006e56c0(*(undefined4 *)(param_1 + 700));
    }
    if ((*(uint *)(param_1 + 0x40) & 0xc000) == 0x4000) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40);
    }
    FUN_00601360(param_1);
    FUN_006e5340(0x1b,0);
  }
  return;
}

