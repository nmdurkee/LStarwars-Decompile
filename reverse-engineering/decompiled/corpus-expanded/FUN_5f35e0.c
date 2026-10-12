/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f35e0; label: FUN_005f35e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f35e0(int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  int local_408;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_408;
  if (DAT_009738cc < 0x10) {
    *(uint *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
  }
  DAT_009738c4 = 2;
  _vsprintf(local_404,param_5,&stack0x00000018);
  FUN_005d0d60(param_1,local_404);
  local_408 = FUN_006e6b90();
  if (param_4 != 0x10) {
    if (param_4 == 0x20) {
      local_408 = param_2 - local_408;
      goto LAB_005f3696;
    }
    if (param_4 == 0x40) {
      local_408 = param_2 - local_408 / 2;
      goto LAB_005f3696;
    }
  }
  local_408 = param_2;
LAB_005f3696:
  iVar2 = param_1;
  if ((param_1 != 0) || (iVar2 = DAT_009738b8, DAT_009738b8 != 0)) {
    if ((DAT_009738c4 & 2) == 0) {
      iVar1 = *(int *)(iVar2 + 0x40) + 4;
    }
    else {
      iVar1 = 0;
    }
    FUN_005d10e0(iVar1,iVar2,(float)local_408,(float)param_3,0);
  }
  FUN_005f3510(param_1,local_404);
  if (0 < DAT_009738cc) {
    DAT_009738c4 = *(uint *)(&DAT_0096d86c + DAT_009738cc * 4);
    DAT_009738cc = DAT_009738cc + -1;
  }
  __security_check_cookie(local_4 ^ (uint)&local_408);
  return;
}

