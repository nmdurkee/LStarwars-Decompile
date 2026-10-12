/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612830; label: FUN_00612830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612830(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006be780(param_2);
  *(undefined4 *)(in_ECX + 0xd5b4 + iVar1 * 4) = param_1;
  return;
}

