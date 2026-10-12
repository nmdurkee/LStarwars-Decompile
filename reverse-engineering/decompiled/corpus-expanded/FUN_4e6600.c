/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e6600; label: FUN_004e6600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e6600(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 0x30;
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5d,iVar1);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5e,iVar1);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x5f,iVar1);
  FUN_00571b60(*(undefined4 *)(PTR_DAT_00802c54 + 0x138),4,iVar1);
  if (*(char *)(param_1 + 0x206) == '\x01') {
    if (param_2 == 4) {
      FUN_0046d780(iVar1,0,1000,0);
      return;
    }
    if (param_2 == 5) {
      FUN_0046d780(iVar1,1,1000,0);
      return;
    }
  }
  else {
    FUN_0046d780(iVar1,0xffffffff,0,1);
  }
  return;
}

