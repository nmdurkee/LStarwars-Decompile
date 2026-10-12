/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46db00; label: FUN_0046db00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0046db00(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x5070) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xeb) != '\0') {
    uVar2 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x5070) = uVar2;
    puVar1 = *(undefined4 **)(param_1 + 0x5070);
    *(uint *)(param_1 + 0x104) = uVar2 + 8;
    *puVar1 = 0;
    puVar1[1] = 0;
    uVar2 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x104) = uVar2;
    *(uint *)(*(int *)(param_1 + 0x5070) + 4) = uVar2;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfc) * 0x90;
    _memset(*(void **)(*(int *)(param_1 + 0x5070) + 4),0,
            (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfc) * 0x90);
  }
  return *(undefined4 *)(param_1 + 0x5070);
}

