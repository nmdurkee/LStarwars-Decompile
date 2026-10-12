/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efc30; label: FUN_004efc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004efc30(int *param_1)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = 0;
  for (puVar2 = (uint *)(*param_1 + 0x10); puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[1]) {
    iVar1 = iVar1 + (*puVar2 & 0x7fffffff);
  }
  return iVar1;
}

