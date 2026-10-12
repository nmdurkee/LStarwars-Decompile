/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49dfd0; label: FUN_0049dfd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049dfd0(int param_1,int param_2)

{
  float fVar1;
  undefined2 local_4;
  
  if (*(char *)(param_1 + 0x7b5) == '\t') {
    fVar1 = _DAT_00925018 + *(float *)(param_1 + 0x77c);
    *(float *)(param_1 + 0x77c) = fVar1;
    if (NAN(fVar1)) {
      fVar1 = *(float *)(param_1 + 0x77c) / *(float *)(param_1 + 0x784);
    }
    else if (param_2 == 0) {
      fVar1 = 1.0;
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
    else {
      FUN_0058e3b0(param_1);
      fVar1 = 1.0;
    }
    if (*(char *)(param_1 + 0x7af) == '\x01') {
      local_4 = (short)(int)ROUND(fVar1 * -32768.0);
      local_4 = *(short *)(param_1 + 0x7a6) - local_4;
      *(short *)(param_1 + 0x27a) = local_4;
      *(short *)(param_1 + 0x5a) = local_4;
      *(short *)(param_1 + 0x58) = local_4;
      return;
    }
    local_4 = (short)(int)ROUND(fVar1 * 32768.0);
    local_4 = *(short *)(param_1 + 0x7a6) - local_4;
    *(short *)(param_1 + 0x27a) = local_4;
    *(short *)(param_1 + 0x5a) = local_4;
    *(short *)(param_1 + 0x58) = local_4;
  }
  return;
}

