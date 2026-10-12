/* Ghidra analysis pseudocode, not original source.
 * ev_90cdd648c2da38df3e143f8257cf22e5b1942b178da0f5c322cb3d7ec211647f
 * Entry: 0x6ff141; label: FUN_006ff141
 */

int FUN_006ff141(short *param_1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}

