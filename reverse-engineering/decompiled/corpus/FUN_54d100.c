/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54d100; label: FUN_0054d100
 */

void FUN_0054d100(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  float fVar2;
  int in_EAX;
  int in_ECX;
  float10 fVar3;
  
  puVar1 = (undefined4 *)(in_ECX + 0x30);
  if (in_EAX == 0) {
    *puVar1 = *param_1;
    *(undefined4 *)(in_ECX + 0x34) = param_1[1];
    *(undefined4 *)(in_ECX + 0x38) = param_1[2];
  }
  else {
    FUN_005b35a0(puVar1);
    FUN_005b3620(puVar1,puVar1,*(undefined2 *)(in_ECX + 0x20));
    FUN_005b37d0(puVar1,puVar1,param_1);
  }
  *(undefined4 *)(in_ECX + 0x3c) = *puVar1;
  *(float *)(in_ECX + 0x40) = *(float *)(in_ECX + 0x34) - 0.1;
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(in_ECX + 0x38);
  *(undefined4 *)(in_ECX + 0x24) = *puVar1;
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x38);
  if (param_2 == 0) {
    FUN_0067a6d0();
  }
  fVar3 = (float10)FUN_005506f0(0,puVar1,0x40a00000,0xffffffff);
  fVar2 = (float)fVar3;
  *(float *)(in_ECX + 0x28) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(in_ECX + 0x28) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,in_ECX + 0x48,in_ECX + 0x4a);
    return;
  }
  return;
}

