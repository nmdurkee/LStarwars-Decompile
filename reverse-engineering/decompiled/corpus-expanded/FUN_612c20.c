/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612c20; label: FUN_00612c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00612c20(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  piVar4 = (int *)(in_ECX + 0xd038);
  do {
    uVar2 = FUN_00617a00();
    if (*piVar4 + 1000U < uVar2) {
      puVar1 = (undefined4 *)(in_ECX + 0xd034 + iVar3 * 0xc);
      *(undefined4 *)(in_ECX + (iVar3 * 3 + 0x340e) * 4) = 0;
      *puVar1 = 0;
      return puVar1;
    }
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 3;
  } while (iVar3 < 0x20);
  return (undefined4 *)0x0;
}

