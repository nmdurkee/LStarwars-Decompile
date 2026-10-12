/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46db00; label: FUN_0046db00
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

