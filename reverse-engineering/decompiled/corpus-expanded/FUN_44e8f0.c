/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44e8f0; label: FUN_0044e8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0044e8f0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_4;
  
  iVar3 = 0;
  local_4 = 1;
  if (((in_stack_00000018 != 0) && (in_stack_00000014 != 0)) && (iVar4 = 0, 0 < in_stack_00000014))
  {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"FALSE");
        if (iVar1 == 0) {
          local_4 = 0;
        }
      }
      else {
        piVar2 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                     iVar1 + 5);
        if (piVar2 != (int *)0x0) {
          iVar3 = *piVar2;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < in_stack_00000014);
    if (iVar3 != 0) {
      *(uint *)(iVar3 + 0x9c) =
           *(uint *)(iVar3 + 0x9c) ^ (local_4 * 4 ^ *(uint *)(iVar3 + 0x9c)) & 4;
    }
  }
  return 1;
}

