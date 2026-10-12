/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x746a00; label: FUN_00746a00
 */

int FUN_00746a00(int *param_1)

{
  int in_ECX;
  int *piVar1;
  char *pcVar2;
  int iVar3;
  
  *(undefined4 *)(in_ECX + 0x990) = 0;
  iVar3 = *param_1;
  if (0x3008 < iVar3) {
    if (iVar3 < 0x6021) {
      if (((iVar3 != 0x6020) && (iVar3 != 0x3020)) && (iVar3 != 0x5020)) goto LAB_00746ae4;
    }
    else if (iVar3 != 0x7020) goto LAB_00746ae4;
    goto LAB_00746ac7;
  }
  if (iVar3 == 0x3008) {
    FUN_007486b0(&DAT_007e9604);
    iVar3 = param_1[3];
  }
  else if (iVar3 < 0x2003) {
    if (iVar3 == 0x2002) {
      pcVar2 = "USE_";
    }
    else {
      if (iVar3 == 0x1004) {
        FUN_007486b0(&DAT_007e9604);
        FUN_00746430(param_1[3]);
        goto LAB_00746ae4;
      }
      if (iVar3 != 0x1020) goto LAB_00746ae4;
LAB_00746ac7:
      pcVar2 = "USE_uniform_";
    }
    FUN_007486b0(pcVar2);
    iVar3 = param_1[3];
  }
  else {
    if (iVar3 != 0x2010) {
      if (iVar3 != 0x2020) goto LAB_00746ae4;
      goto LAB_00746ac7;
    }
    FUN_007486b0("USE_attribute_");
    iVar3 = param_1[3];
  }
  FUN_007486b0(iVar3);
LAB_00746ae4:
  iVar3 = *(int *)(in_ECX + 0x990);
  piVar1 = (int *)(in_ECX + 0x98c);
  if (0 < iVar3) {
    if (*(char *)(*piVar1 + -1 + iVar3) == '\0') {
      return *piVar1;
    }
    if (*(int *)(in_ECX + 0x994) < iVar3 + 1) {
      FUN_007484e0((iVar3 * 3 + 3) / 2);
    }
    *(undefined1 *)(*piVar1 + *(int *)(in_ECX + 0x990)) = 0;
    *(int *)(in_ECX + 0x990) = *(int *)(in_ECX + 0x990) + 1;
  }
  return *piVar1;
}

