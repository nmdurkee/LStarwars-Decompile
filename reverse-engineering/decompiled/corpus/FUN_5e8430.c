/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e8430; label: FUN_005e8430
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e8430(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_0080bd34;
  iVar1 = DAT_0080bd30;
  if ((DAT_0080bbe0 != '\0') && (DAT_0080bbe1 != '\0')) {
    DAT_0080bd30 = DAT_0080bd34;
    DAT_0080bd34 = iVar1;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined1 *)(iVar2 + 0x10) = 0;
    _DAT_0080bd40 = 0;
    _DAT_0080bd44 = 0;
  }
  return;
}

