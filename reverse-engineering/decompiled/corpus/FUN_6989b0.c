/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x6989b0; label: FUN_006989b0
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

