/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612860; label: FUN_00612860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00612860(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int *)(in_ECX + 0xd834) < 0x20) {
    *(undefined4 *)(in_ECX + 0xd6b4 + *(int *)(in_ECX + 0xd834) * 0xc) = 0;
    *(undefined4 *)(in_ECX + 0xd6b8 + *(int *)(in_ECX + 0xd834) * 0xc) = param_2;
    *(undefined4 *)(in_ECX + (*(int *)(in_ECX + 0xd834) + 0x11e5) * 0xc) = param_1;
    *(int *)(in_ECX + 0xd834) = *(int *)(in_ECX + 0xd834) + 1;
    uVar1 = *(undefined4 *)(in_ECX + 0xd834);
  }
  return uVar1;
}

