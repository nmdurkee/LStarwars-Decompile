/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49e240; label: FUN_0049e240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0049e240(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x280) != -1) &&
     (((iVar1 = *(int *)(*(int *)(in_ECX + 0x50) + 0xc), *(int *)(iVar1 + 0x68) != 0 ||
       (*(int *)(iVar1 + 0x6c) != 0)) || (*(int *)(iVar1 + 0x70) != 0)))) {
    uVar2 = FUN_00571cf0();
    return uVar2;
  }
  return 0;
}

