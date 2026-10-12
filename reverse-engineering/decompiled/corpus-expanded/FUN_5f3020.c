/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3020; label: FUN_005f3020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005f3020(int *param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar3 = *param_1 + 0x1fU & 0xffffffe0;
  *param_1 = (*param_1 + 0x1fU & 0xffffffe0) + 0x830;
  FUN_005e8da0(in_ECX);
  param_1 = (int *)0x0;
  if (0 < *(int *)(in_ECX + 0x70c)) {
    puVar2 = (undefined4 *)(in_ECX + 0x2b4);
    do {
      puVar2[0x30] = 0;
      iVar5 = 2;
      puVar4 = puVar2;
      do {
        FUN_005fca40(puVar4[-2]);
        puVar1 = (undefined1 *)*puVar4;
        puVar4[1] = puVar1;
        puVar4 = puVar4 + 0x11;
        iVar5 = iVar5 + -1;
        *puVar1 = 0x8d;
        *(undefined4 *)(puVar1 + 4) = 0;
        puVar1[1] = 1;
      } while (iVar5 != 0);
      param_1 = (int *)((int)param_1 + 1);
      puVar2 = puVar2 + 0xe0;
    } while ((int)param_1 < *(int *)(in_ECX + 0x70c));
    return uVar3;
  }
  return uVar3;
}

