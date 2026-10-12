/* Ghidra analysis pseudocode, not original source.
 * ev_b1d683d72d7bcdb306124a83b006db4b41bf581671bc5ef620d768a8a4b84d3d
 * Entry: 0x66c670; label: FUN_0066c670
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066c670(char *param_1,int *param_2,int *param_3)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  undefined4 *puVar4;
  short sVar5;
  undefined4 *puVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int local_70;
  undefined1 local_6c [4];
  char local_68 [4];
  undefined1 local_64 [96];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_70;
  iVar8 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_68 + iVar8)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  puVar4 = (undefined4 *)(local_6c + 3);
  do {
    puVar6 = puVar4;
    puVar4 = (undefined4 *)((int)puVar6 + 1);
  } while (*(char *)((int)puVar6 + 1) != '\0');
  *(undefined4 *)((int)puVar6 + 1) = 0x7265742e;
  *(undefined1 *)((int)puVar6 + 5) = 0;
  FUN_004fd5d0(local_68,*param_2,0x7fffffff);
  piVar3 = (int *)*param_2;
  local_6c = (undefined1  [4])((int)piVar3 + *piVar3 * 2);
  *param_2 = (int)(piVar3 + 1);
  sVar5 = 0;
  _DAT_02921194 = 0;
  local_70 = 0;
  if (0 < *(short *)local_6c) {
    psVar7 = (short *)((int)local_6c + 0x14);
    iVar8 = 0;
    do {
      iVar9 = iVar8;
      switch(*psVar7) {
      case 0:
      case 1:
        *(short *)(*param_3 + 0x32 + iVar8) = psVar7[0xf];
        sVar2 = *(short *)(*param_3 + 0x32 + iVar8);
        if ((-1 < sVar2) && (sVar2 < 0x80)) {
          *(short *)((int)param_3 + sVar2 * 2 + 0xc) = sVar5;
        }
        *(int *)(iVar8 + 0x2c + *param_3) = (int)*psVar7;
        *(short *)(*param_3 + 0x30 + iVar8) = psVar7[1];
        sVar5 = sVar5 + 1;
        iVar9 = iVar8 + 0x38;
        *(undefined4 *)(iVar8 + *param_3) = *(undefined4 *)(psVar7 + -6);
        *(undefined4 *)(*param_3 + -0x34 + iVar9) = *(undefined4 *)(psVar7 + -4);
        *(undefined4 *)(*param_3 + -0x30 + iVar9) = *(undefined4 *)(psVar7 + -2);
        *(int *)(*param_3 + -0x2c + iVar9) = *param_2;
        *(undefined4 *)(*param_3 + -0x10 + iVar9) = *(undefined4 *)(psVar7 + 0xc);
        break;
      case 2:
        if (*(int *)*param_2 == 0x12345678) {
          *(int *)*param_2 = param_3[0x3a3];
          psVar10 = (short *)(*param_2 + 4);
          param_3[0x3a3] = (int)psVar10;
          *psVar10 = *psVar10 + -1;
        }
        break;
      case 3:
        _DAT_02921194 = *param_2;
      }
      *param_2 = *param_2 + *(int *)(psVar7 + -8) * 2;
      local_70 = local_70 + 1;
      psVar7 = psVar7 + 0x1a;
      iVar8 = iVar9;
    } while (local_70 < *(short *)local_6c);
  }
  __security_check_cookie(local_4 ^ (uint)&local_70);
  return;
}

