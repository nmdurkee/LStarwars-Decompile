/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x6989b0; label: FUN_006989b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006989b0(undefined4 param_1)

{
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  _sprintf(local_44,">>> NuSoundStopStereo %d",param_1);
  FUN_006996b0();
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

