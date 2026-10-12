/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x520fe0; label: FUN_00520fe0
 */

int FUN_00520fe0(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_14;
  float local_c;
  float local_8;
  float local_4;
  
  local_14 = 3.4028235e+38;
  iVar3 = 0;
  iVar2 = FUN_004f1440(DAT_009238e4 + 0x383c0);
  do {
    if (iVar2 == 0) {
      return iVar3;
    }
    fVar4 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x28,iVar2 + 0x18,&local_c);
    fVar1 = (float)fVar4;
    if (fVar1 < local_14) {
      local_8 = *(float *)(DAT_009238e4 + 0x2c) - *(float *)(iVar2 + 0x1c);
      if (param_1 == 0) {
LAB_00521097:
        iVar3 = iVar2;
        local_14 = fVar1;
      }
      else if ((*(byte *)(iVar2 + 0x33) & 1) == 0) {
        FUN_005b3620(&local_c,&local_c,-(int)*(short *)(iVar2 + 0x30));
        if (((((local_c < *(float *)(iVar2 + 0x24)) && (local_8 < *(float *)(iVar2 + 0x28))) &&
             (local_4 < *(float *)(iVar2 + 0x2c))) &&
            ((-*(float *)(iVar2 + 0x24) < local_c && (-2.0 < local_8)))) &&
           (-*(float *)(iVar2 + 0x2c) < local_4)) {
          iVar3 = iVar2;
          local_14 = fVar1;
        }
      }
      else if (((fVar1 < *(float *)(iVar2 + 0x24) * *(float *)(iVar2 + 0x24)) &&
               (local_8 < *(float *)(iVar2 + 0x28))) && (-2.0 < local_8)) goto LAB_00521097;
    }
    iVar2 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar2);
  } while( true );
}

