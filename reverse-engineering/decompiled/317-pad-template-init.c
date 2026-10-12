/* ev_4534c921e9747250cc982e675dab2d31fd633d6493b461cc5ae99dc55bff0028 */

void FUN_006d3aa0(void)

{
  undefined4 uVar1;
  void *in_ECX;
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  uVar1 = FUN_006dd420(PTR_s_TTales_00827618,PTR_s_GameTitle_0082761c);
  _sprintf(local_404,"%s\\%s\\%s\\",uVar1);
  _memset(in_ECX,0,0x2700);
  FUN_006d3990(in_ECX,local_404);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

