/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f7a60; label: FUN_005f7a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f7a60(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((param_1 == 1) &&
     ((((in_ECX == 4 || (in_ECX == 5)) || (in_ECX == 6)) || (uVar1 = 1, in_ECX == 7)))) {
    uVar1 = 2;
  }
  return uVar1;
}

