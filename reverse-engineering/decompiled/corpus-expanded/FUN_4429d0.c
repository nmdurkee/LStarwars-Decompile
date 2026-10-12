/* Ghidra pseudocode, not original source.
 * ev_6293e9c45219377b80e3d0963b70152e043cc5400ac7177165af43f16814c89d
 * Entry: 0x4429d0; label: FUN_004429d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004429d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    if ((*(int *)(*piVar1 + 0xe64) != 0) && (*(char *)(*piVar1 + 0xe6b) == '\0')) {
      return (float10)0;
    }
    return (float10)1;
  }
  return (float10)-1.0;
}

