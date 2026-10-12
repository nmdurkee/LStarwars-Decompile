/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46f990; label: FUN_0046f990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0046f990(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x5100) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0x104) != '\0') {
    uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x5100) = uVar2;
    puVar1 = *(undefined4 **)(param_1 + 0x5100);
    *(uint *)(param_1 + 0x104) = uVar2 + 0xc;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar2;
    **(uint **)(param_1 + 0x5100) = uVar2;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x104) * 0x2c;
    _memset((void *)**(undefined4 **)(param_1 + 0x5100),0,
            (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x104) * 0x2c);
    *(undefined4 *)(*(int *)(param_1 + 0x5100) + 8) = 0x3f800000;
  }
  return *(undefined4 *)(param_1 + 0x5100);
}

