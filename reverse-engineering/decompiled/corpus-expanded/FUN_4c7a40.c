/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c7a40; label: FUN_004c7a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004c7a40(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if ((param_3 & 1) != 0) {
      return param_2 == (*(byte *)(iVar1 + 0x6a) >> 1 & 1);
    }
    *(byte *)(iVar1 + 0x6a) =
         *(byte *)(iVar1 + 0x6a) ^ ((param_2 == 0) * '\x02' ^ *(byte *)(iVar1 + 0x6a)) & 2;
    return true;
  }
  return false;
}

