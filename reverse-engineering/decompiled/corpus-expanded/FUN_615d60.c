/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x615d60; label: FUN_00615d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00615d60(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int in_ECX;
  
  if (((param_1 != 0) && (*(int *)(in_ECX + 0x3c + param_1 * 0x18) != 0)) &&
     (puVar1 = (ushort *)(in_ECX + (param_1 * 3 + 6) * 8), puVar1 != (ushort *)0x0)) {
    if (*(char *)(*(int *)(puVar1 + 4) + 0xc) != '\0') {
      return 1;
    }
    uVar2 = *puVar1;
    if ((uVar2 & 8) == 0) {
      return 0;
    }
    iVar3 = FUN_00612950(*(int *)(puVar1 + 4));
    if (iVar3 != 0) {
      if ((uVar2 & 0x20) != 0) {
        return 0;
      }
      puVar4 = (undefined4 *)FUN_00612bd0(puVar1);
      if (((puVar4 == (undefined4 *)0x0) &&
          (puVar4 = (undefined4 *)FUN_00612bd0(0), puVar4 == (undefined4 *)0x0)) &&
         (puVar4 = (undefined4 *)FUN_00612c20(), puVar4 == (undefined4 *)0x0)) {
        return 0;
      }
      uVar5 = FUN_00617a00();
      if (uVar5 <= (uint)puVar4[1]) {
        return 0;
      }
      *puVar4 = 1;
      puVar4[1] = uVar5 + 0xfa;
      puVar4[2] = puVar1;
      FUN_00615650(puVar1);
      return 0;
    }
  }
  return 0xffffffff;
}

