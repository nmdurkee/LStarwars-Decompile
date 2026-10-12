/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464140; label: FUN_00464140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464140(int param_1,int param_2,float param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_2 + 0xb9);
  if (cVar1 == '\x03') {
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      uVar2 = *(uint *)(param_2 + 0xb0);
      if (((((uVar2 & 0x400) == 0) && (*(char *)(param_2 + 0xba) == '\0')) && ((uVar2 & 0x40) == 0))
         && ((*(char *)(param_2 + 0xa7) == '\0' && (*(char *)(param_2 + 0xa6) == '\0')))) {
        *(uint *)(param_2 + 0xb0) = uVar2 | 0x1000;
      }
      FUN_004838f0(param_2);
      return;
    }
  }
  else {
    if (cVar1 == '\x02') {
      iVar3 = FUN_0050b310();
    }
    else {
      iVar3 = DAT_00921df8;
      if (cVar1 == '\0') {
        *(undefined1 *)(param_2 + 0xb9) = 1;
        FUN_004cf4b0();
        iVar3 = FUN_0050c000();
        if (iVar3 != 0) {
          return;
        }
        *(undefined1 *)(param_2 + 0xb9) = 2;
        FUN_00509830();
        return;
      }
    }
    if (iVar3 == 0) {
      *(undefined1 *)(param_2 + 0xb9) = 3;
    }
  }
  return;
}

