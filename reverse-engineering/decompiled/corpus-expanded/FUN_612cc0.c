/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612cc0; label: FUN_00612cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00612cc0(int param_1)

{
  int iVar1;
  int extraout_ECX;
  
  if (param_1 != 0) {
    iVar1 = FUN_00612b60(param_1);
    if (iVar1 != 0) {
      return (int)*(short *)(iVar1 + 2);
    }
    if (*(char *)(extraout_ECX + 0xd96c) != '\0') {
      FUN_00611890(param_1);
    }
  }
  return 0;
}

