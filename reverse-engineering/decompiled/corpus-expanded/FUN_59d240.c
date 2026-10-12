/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59d240; label: FUN_0059d240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059d240(float param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  uint uVar5;
  int *in_ECX;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float local_2c;
  float local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2c;
  if (DAT_009562b4 == 0) {
    fVar3 = (param_1 / _DAT_00805434) * _DAT_009562ac;
    DAT_009562b4 = 0;
    iVar2 = *in_ECX;
    local_28 = fVar3;
    while (iVar2 != 0) {
      if (((float)in_ECX[2] < fVar3 != ((float)in_ECX[2] == fVar3)) &&
         (fVar3 <= (float)in_ECX[2] + 2.2)) {
        local_2c = (float)(uint)*(byte *)((int)in_ECX + 0x13);
        uVar4 = FUN_006e6b90();
        local_2c = (float)((float10)-1.0 - ((float10)(float)in_ECX[2] - extraout_ST0));
        FUN_0050d910(iVar2,in_ECX[1],local_2c,0x3f800000,in_ECX[3],in_ECX[3],in_ECX[3],
                     (char)in_ECX[5],(char)in_ECX[4],*(undefined1 *)((int)in_ECX + 0x11),
                     *(undefined1 *)((int)in_ECX + 0x12),
                     *(undefined4 *)(&DAT_00805440 + *(char *)((int)in_ECX + 0x15) * 0x18),1,0,0,
                     uVar4);
        fVar3 = local_28;
      }
      piVar1 = in_ECX + 6;
      in_ECX = in_ECX + 6;
      iVar2 = *piVar1;
    }
    __security_check_cookie(local_4 ^ (uint)&local_2c);
    return;
  }
  if (DAT_0093b2b4 == (ushort *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)*DAT_0093b2b4;
  }
  local_2c = (float)(uVar5 * 100);
  _sprintf(local_24,"%.1f%%",(double)(int)local_2c / (double)DAT_0093b2b8);
  local_28 = 0.0;
  if (DAT_009562b4 == 1) {
    local_28 = _DAT_009562b8 * -0.1 + 0.1;
  }
  else if (DAT_009562b4 == 3) {
    local_28 = 0.0 - (1.0 - _DAT_009562b8) * 0.1;
  }
  local_2c = (float)FUN_006e6b90();
  uVar4 = FUN_006e6b90();
  FUN_0050d910(local_24,local_28,(float)extraout_ST0_00,0x3f800000,0x3fe00000,0x3fe00000,0x3fe00000,
               0,0xff,0xbf,0,0x3fd9999a,1,0,0,uVar4);
  __security_check_cookie(local_4 ^ (uint)&local_2c);
  return;
}

