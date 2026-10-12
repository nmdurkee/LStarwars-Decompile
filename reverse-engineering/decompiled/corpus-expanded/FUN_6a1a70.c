/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1a70; label: FUN_006a1a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a1a70(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  iVar2 = FUN_006a16b0(param_1,param_2,1);
  if (iVar2 != 0) {
    return 1;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x68);
  uVar3 = FUN_006a3e50(param_2);
  puVar1[0xf] = uVar3;
  pvVar4 = _calloc(1,0xb4);
  *puVar1 = pvVar4;
  FUN_006b09f0(pvVar4,param_2);
  FUN_006b0350(param_2,puVar1 + 0x14);
  *(undefined4 *)(param_1 + 0x40) = 3;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return 0;
}

