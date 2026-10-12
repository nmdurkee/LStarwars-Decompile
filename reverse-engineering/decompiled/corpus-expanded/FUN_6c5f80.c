/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5f80; label: FUN_006c5f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c5f80(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (((param_1 != iVar1) && ((iVar1 != DAT_02973ad0 || (param_1 != DAT_02973ab8)))) &&
     ((iVar1 != DAT_02973ad4 || (param_1 != DAT_02973abc)))) {
    if ((param_1 < 0) || (DAT_02973ba4 <= param_1)) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(DAT_02973b8c + param_1 * 0xc);
    }
    if ((-1 < iVar1) && (iVar1 < DAT_02973ba4)) {
      FUN_006b7c40(*puVar2,*(undefined4 *)(DAT_02973b8c + iVar1 * 0xc));
      return;
    }
    FUN_006b7c40(*puVar2,uRam00000000);
  }
  return;
}

