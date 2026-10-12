/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46f730; label: FUN_0046f730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046f730(int *param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) &&
     (*(byte *)(iVar1 + 0x62) =
           *(byte *)(iVar1 + 0x62) ^ ((param_2 != 0) * '\b' ^ *(byte *)(iVar1 + 0x62)) & 8,
     param_2 != 0)) {
    FUN_0046f4d0(iVar1);
  }
  return;
}

