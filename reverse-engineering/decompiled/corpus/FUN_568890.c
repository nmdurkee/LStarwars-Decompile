/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x568890; label: FUN_00568890
 */

void FUN_00568890(int param_1,int param_2,int param_3)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if (param_1 != 0) {
    FUN_005b44e0(param_2);
    if (param_3 == 0) {
      fVar1 = (1.0 - *(float *)(param_1 + 0xbc) * 10.0) * *(float *)(param_1 + 0xc0);
    }
    else {
      fVar1 = *(float *)(param_1 + 0xc0);
    }
    FUN_005b4ac0(param_2,fVar1);
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(undefined4 *)(param_2 + 0x38) = 0;
    FUN_005b4f70(param_2,*(undefined2 *)(param_1 + 0xde));
    FUN_005b4dd0(param_2,*(undefined2 *)(param_1 + 0xdc));
    FUN_005b5060(param_2,*(undefined2 *)(param_1 + 0xe0));
    local_c = *(float *)(param_1 + 0x70) + *(float *)(param_1 + 0x30);
    local_8 = *(float *)(param_1 + 0x74) + *(float *)(param_1 + 0x34);
    local_4 = *(float *)(param_1 + 0x78) + *(float *)(param_1 + 0x38);
    FUN_005b4900(param_2,&local_c);
  }
  return;
}

