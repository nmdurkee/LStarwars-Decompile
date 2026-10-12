/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d7800; label: FUN_004d7800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d7800(int param_1,uint *param_2,undefined4 *param_3)

{
  undefined2 uVar1;
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
    DAT_00881c34 = FUN_005e4d40(1);
    *(uint *)(DAT_00881c34 + 0x40) = *(uint *)(DAT_00881c34 + 0x40) & 0xfffffcff;
    *(uint *)(DAT_00881c34 + 0x40) = *(uint *)(DAT_00881c34 + 0x40) & 0xfffff3ff;
    *(undefined4 *)(DAT_00881c34 + 0x70) = 0x3f800000;
    *(uint *)(DAT_00881c34 + 0x40) = *(uint *)(DAT_00881c34 + 0x40) & 0xffff3fff;
    *(uint *)(DAT_00881c34 + 0x40) = *(uint *)(DAT_00881c34 + 0x40) & 0xfffffff0;
    *(uint *)(DAT_00881c34 + 0x40) = *(uint *)(DAT_00881c34 + 0x40) & 0xffffffdf | 0x10;
    *(uint *)(DAT_00881c34 + 0x40) = *(uint *)(DAT_00881c34 + 0x40) & 0xfffcffff;
    FUN_004f1e80(&local_44,param_1);
    *param_2 = *param_2 + 0xf & 0xfffffff0;
    uVar1 = FUN_005f8d60(&local_44,param_2,*param_3);
    *(undefined2 *)(DAT_00881c34 + 0x74) = uVar1;
    if (*(short *)(DAT_00881c34 + 0x74) != 0) {
      FUN_005e4b00(DAT_00881c34);
      __security_check_cookie(local_4 ^ (uint)&local_44);
      return;
    }
    FUN_005e50e0();
  }
  DAT_00881c34 = 0;
  __security_check_cookie(local_4 ^ (uint)&local_44);
  return;
}

