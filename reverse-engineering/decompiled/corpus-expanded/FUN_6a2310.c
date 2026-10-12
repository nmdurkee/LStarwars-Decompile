/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a2310; label: FUN_006a2310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a2310(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x68);
  if (((iVar1 != 0) && (*(int *)(param_1 + 4) != 0)) &&
     (iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x1c), iVar3 != 0)) {
    bVar2 = (byte)*(undefined4 *)(iVar3 + 0xe48);
    iVar3 = *(int *)(iVar3 + 4) >> (bVar2 + 1 & 0x1f);
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(int *)(param_1 + 0x30) = iVar3;
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(int *)(param_1 + 0x14) = iVar3 >> (bVar2 & 0x1f);
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x80) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x84) = 0xffffffff;
    return 0;
  }
  return 0xffffffff;
}

