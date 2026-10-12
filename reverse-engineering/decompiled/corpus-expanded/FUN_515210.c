/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x515210; label: FUN_00515210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515210(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) && (*(int *)(param_3 + 0x158) != 0)) &&
     ((iVar1 = *(int *)(*(int *)(param_3 + 0xe4) + 4), iVar1 != 0 &&
      (*(int *)(param_3 + 0x158) == *(int *)(iVar1 + 0x158))))) {
    return (float10)1;
  }
  return (float10)0;
}

