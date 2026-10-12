/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42fa70; label: FUN_0042fa70
 */

void FUN_0042fa70(int param_1,int *param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_44;
  undefined2 local_40;
  undefined1 local_3e;
  undefined1 local_3d [57];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_44;
  local_44 = 0x66757473;
  local_40 = 0x5c66;
  local_3e = 0;
  _memset(local_3d,0,0x39);
  if (param_1 != 0) {
    FUN_004f1e80(&local_44,param_1);
    *param_3 = *param_3 + 0xf & 0xfffffff0;
    FUN_004f1e80(&local_44,&DAT_00755ae4);
    iVar1 = FUN_005f8d60(&local_44,param_3,*param_4);
    if (iVar1 != 0) {
      iVar2 = FUN_005e4d60(1,1);
      *param_2 = iVar2;
      *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xfffffcff;
      *(uint *)(*param_2 + 0x40) = *(uint *)(*param_2 + 0x40) & 0xfffff3ff;
      *(undefined4 *)(*param_2 + 0x70) = 0x3f800000;
      *(uint *)(*param_2 + 0x40) = *(uint *)(*param_2 + 0x40) & 0xffff7fff | 0x4000;
      *(uint *)(*param_2 + 0x40) = *(uint *)(*param_2 + 0x40) & 0xfffffff2 | 2;
      *(uint *)(*param_2 + 0x40) = *(uint *)(*param_2 + 0x40) & 0xffffffdf | 0x10;
      *(uint *)(*param_2 + 0x40) = *(uint *)(*param_2 + 0x40) & 0xfffeffff | 0x20000;
      *(short *)(*param_2 + 0x74) = (short)iVar1;
      FUN_005e4b00(*param_2);
      __security_check_cookie(local_4 ^ (uint)&local_44);
      return;
    }
  }
  *param_2 = 0;
  __security_check_cookie(local_4 ^ (uint)&local_44);
  return;
}

