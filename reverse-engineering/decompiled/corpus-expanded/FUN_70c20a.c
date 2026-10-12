/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70c20a; label: _ProcessCodePage
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    _ProcessCodePage
   
   Library: Visual Studio 2005 Release */

void _ProcessCodePage(void)

{
  int iVar1;
  CHAR *in_ECX;
  int unaff_EDI;
  LCTYPE LCType;
  CHAR local_10 [8];
  uint local_8;
  
  local_8 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  if ((in_ECX == (char *)0x0) || (*in_ECX == '\0')) {
LAB_0070c252:
    LCType = 0x1004;
LAB_0070c25d:
    iVar1 = GetLocaleInfoA(*(LCID *)(unaff_EDI + 0x1c),LCType,local_10,8);
    if (iVar1 == 0) goto LAB_0070c274;
    in_ECX = local_10;
  }
  else {
    iVar1 = _strcmp(in_ECX,"ACP");
    if (iVar1 == 0) goto LAB_0070c252;
    iVar1 = _strcmp(in_ECX,"OCP");
    if (iVar1 == 0) {
      LCType = 0xb;
      goto LAB_0070c25d;
    }
  }
  _atol(in_ECX);
LAB_0070c274:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

