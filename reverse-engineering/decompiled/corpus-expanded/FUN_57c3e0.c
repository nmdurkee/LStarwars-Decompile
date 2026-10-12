/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57c3e0; label: FUN_0057c3e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057c3e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint *param_5
                 ,undefined4 param_6,undefined4 param_7,int param_8,undefined4 param_9)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  undefined4 local_218;
  int local_214;
  uint local_210;
  undefined4 local_20c;
  undefined4 local_208;
  uint auStack_204 [31];
  char acStack_185 [129];
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_218;
  local_20c = param_2;
  local_208 = param_3;
  local_218 = param_6;
  if ((DAT_00951ca4 != 0) && (0 < DAT_00951ca8)) {
    FUN_0057c110(param_2,param_4,param_5,param_7,param_8,param_9);
    __security_check_cookie(local_4 ^ (uint)&local_218);
    return;
  }
  if ((param_1 == 0) ||
     (iVar3 = FUN_004fc900("cutscenes",param_1,0xffff), local_214 = iVar3, iVar3 == 0)) {
    __security_check_cookie(local_4 ^ (uint)&local_218);
    return;
  }
  local_210 = *param_5;
  puVar5 = (uint *)(local_210 + 3 & 0xfffffffc);
  *param_5 = (uint)(puVar5 + 3);
  puVar5[2] = (uint)(puVar5 + 3);
  DAT_00951c60 = param_9;
  DAT_00951bec = param_7;
  DAT_00951c64 = puVar5;
  *param_5 = *param_5 + 3 +
             ((int)(DAT_0093b278 + 0x1f + (DAT_0093b278 + 0x1f >> 0x1f & 0x1fU)) >> 5) * 4 &
             0xfffffffc;
  iVar4 = FUN_004fc5b0(iVar3);
  do {
    if (iVar4 == 0) {
      FUN_004fa300(iVar3);
      if ((int)puVar5[1] < 1) {
        *param_5 = local_210;
        __security_check_cookie(local_4 ^ (uint)&local_218);
        return;
      }
      uVar1 = *param_5;
      iVar3 = puVar5[1] * 4;
      *puVar5 = uVar1;
      FUN_004ef660(uVar1,auStack_204,iVar3);
      *param_5 = puVar5[1] * iVar3 + 3 + *param_5 & 0xfffffffc;
      __security_check_cookie(local_4 ^ (uint)&local_218);
      return;
    }
    iVar4 = FUN_004f7fb0(iVar3);
    if ((((iVar4 != 0) &&
         (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"cutscene"), iVar4 == 0)) &&
        ((int)puVar5[1] < 0x20)) && (iVar4 = FUN_004f7fb0(iVar3), iVar4 != 0)) {
      uVar1 = *param_5;
      auStack_204[puVar5[1]] = uVar1;
      *param_5 = uVar1 + 0x193 & 0xfffffffc;
      piVar2 = (int *)auStack_204[puVar5[1]];
      FUN_004f8c60(acStack_185 + 1,*(undefined4 *)(local_214 + 0x510));
      iVar3 = FUN_004f1ff0(acStack_185 + 1);
      do {
        iVar4 = iVar3;
        if (iVar4 + -1 < 1) break;
        iVar3 = iVar4 + -1;
      } while (acStack_185[iVar4] != '.');
      if (acStack_185[iVar4] == '.') {
        acStack_185[iVar4] = '\0';
      }
      if (((acStack_185[1] == 'c') && (acStack_185[2] == 'u')) &&
         ((acStack_185[3] == 't' && (acStack_185[4] == '\\')))) {
        FUN_004f1f10(acStack_185 + 1,acStack_185 + 5);
      }
      FUN_004f1f10(local_84,acStack_185 + 1);
      if (DAT_00951ca0 != (code *)0x0) {
        (*DAT_00951ca0)(local_84,param_7,param_8);
      }
      FUN_004f1f10(local_104,&DAT_007625c8);
      FUN_004f1e80(local_104,local_84);
      FUN_004f1e80(local_104,&DAT_0075d39c);
      FUN_0057bd50(local_104);
      FUN_004f1f10(local_104,&DAT_007625c8);
      FUN_004f1e80(local_104,acStack_185 + 1);
      FUN_004f1e80(local_104,&DAT_0075d39c);
      if ((((piVar2[0x14] & 0x800U) == 0) && (iVar3 = FUN_0055c690(), iVar3 == 0)) &&
         ((*(byte *)(param_8 * 0x130 + 100 + DAT_00951b78) & 0xe0) == 0)) {
LAB_0057c887:
        *param_5 = uVar1;
        iVar3 = local_214;
      }
      else {
        *param_5 = *param_5 + 0x3f & 0xffffffc0;
        FUN_004f1f10(local_104,&DAT_007625c8);
        FUN_004f1e80(local_104,acStack_185 + 1);
        FUN_004f1e80(local_104,&DAT_0075eb00);
        iVar3 = FUN_00505820(local_104,param_5,local_218,0);
        *piVar2 = iVar3;
        if (iVar3 == 0) {
          FUN_004f1f10(local_104,&DAT_007625c8);
          FUN_004f1e80(local_104,acStack_185 + 1);
          FUN_004f1e80(local_104,&DAT_007625d0);
          iVar3 = FUN_00505820(local_104,param_5,local_218,0);
          *piVar2 = iVar3;
          if (iVar3 == 0) goto LAB_0057c887;
        }
        iVar3 = FUN_004f1ff0(acStack_185 + 1);
        iVar3 = iVar3 + -1;
        if (iVar3 < 0) {
LAB_0057c801:
          pcVar6 = acStack_185 + 1;
        }
        else {
          do {
            if (acStack_185[iVar3 + 1] == '\\') {
              if (iVar3 < 0) goto LAB_0057c801;
              pcVar6 = acStack_185 + iVar3 + 2;
              goto LAB_0057c81b;
            }
            iVar3 = iVar3 + -1;
          } while (-1 < iVar3);
          pcVar6 = acStack_185 + 1;
        }
LAB_0057c81b:
        FUN_004f1f10(piVar2 + 2,pcVar6);
        FUN_00505b40(*piVar2,local_20c,0,param_4);
        FUN_00505bb0(*piVar2,local_208);
        iVar3 = FUN_00505cf0(*piVar2,0,0,acStack_185 + 1,param_5,0);
        piVar2[1] = iVar3;
        if (iVar3 != 0) {
          *(float *)(iVar3 + 0x98) = (float)piVar2[0x17] * _DAT_0092501c;
          *param_5 = *param_5 + 0xf & 0xfffffff0;
        }
        puVar5[1] = puVar5[1] + 1;
        iVar3 = local_214;
      }
    }
    iVar4 = FUN_004fc5b0(iVar3);
  } while( true );
}

