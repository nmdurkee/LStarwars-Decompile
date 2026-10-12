/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70b6d4; label: FUN_0070b6d4
 */

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0070b6d4(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char in_AL;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int *in_EDX;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  
  if (in_AL < 'Z') {
    if (in_AL == 'Y') {
      if ((-0x76d < in_EDX[5]) && (in_EDX[5] < 0x1fa4)) goto LAB_0070b91f;
LAB_0070b887:
      puVar3 = (undefined4 *)FUN_006ead5f();
      goto LAB_0070b9af;
    }
    if (in_AL < 'J') {
      if (in_AL == 'I') {
        if ((-1 < in_EDX[2]) && (in_EDX[2] < 0x18)) goto LAB_0070b91f;
      }
      else {
        if (in_AL == '\x04') {
          return 1;
        }
        if (in_AL == '\r') {
          return 1;
        }
        if (in_AL == '%') {
          *(undefined1 *)*in_ECX = 0x25;
          *in_ECX = *in_ECX + 1;
          *param_2 = *param_2 + -1;
          return 1;
        }
        if (in_AL == 'A') {
          iVar2 = in_EDX[6];
joined_r0x0070b9a3:
          if ((-1 < iVar2) && (iVar2 < 7)) goto LAB_0070baaa;
        }
        else if (in_AL == 'B') {
          iVar2 = in_EDX[4];
joined_r0x0070b989:
          if ((-1 < iVar2) && (iVar2 < 0xc)) goto LAB_0070baaa;
        }
        else {
          if (in_AL != 'H') {
            return 0;
          }
          iVar1 = in_EDX[2];
          if (-1 < iVar1) {
            bVar5 = SBORROW4(iVar1,0x17);
            iVar2 = iVar1 + -0x17;
            bVar4 = iVar1 == 0x17;
            goto LAB_0070b738;
          }
        }
      }
    }
    else {
      if (in_AL == 'M') {
        iVar2 = in_EDX[1];
      }
      else {
        if (in_AL != 'S') {
          if (in_AL == 'U') {
            iVar2 = in_EDX[6];
          }
          else {
            if (in_AL != 'W') {
              if (in_AL != 'X') {
                return 0;
              }
LAB_0070b966:
              uVar6 = 2;
LAB_0070b96a:
              iVar2 = FUN_0070baba(param_1,uVar6);
              if (iVar2 == 0) {
                return 0;
              }
              return 1;
            }
            iVar2 = in_EDX[6];
          }
          if ((-1 < iVar2) && (iVar2 < 7)) {
            iVar2 = in_EDX[7];
joined_r0x0070b8e6:
            if ((-1 < iVar2) && (iVar2 < 0x16e)) goto LAB_0070b91f;
          }
          goto LAB_0070b9aa;
        }
        iVar2 = *in_EDX;
      }
      if (-1 < iVar2) {
        bVar5 = SBORROW4(iVar2,0x3b);
        iVar2 = iVar2 + -0x3b;
        bVar4 = iVar2 == 0;
LAB_0070b738:
        if (bVar4 || bVar5 != iVar2 < 0) {
LAB_0070b91f:
          FID_conflict___store_num(param_4);
          return 1;
        }
      }
    }
  }
  else if (in_AL < 'n') {
    if (in_AL != 'm') {
      if (in_AL == 'Z') {
LAB_0070ba01:
        ___tzset();
        FUN_007133c7();
LAB_0070baaa:
        FUN_0070b605();
        return 1;
      }
      if (in_AL == 'a') {
        iVar2 = in_EDX[6];
        goto joined_r0x0070b9a3;
      }
      if (in_AL == 'b') {
        iVar2 = in_EDX[4];
        goto joined_r0x0070b989;
      }
      if (in_AL == 'c') {
        iVar2 = FUN_0070baba(param_1,param_4 != 0);
        if (iVar2 == 0) {
          return 0;
        }
        if (*param_2 == 0) {
          return 0;
        }
        *(undefined1 *)*in_ECX = 0x20;
        *in_ECX = *in_ECX + 1;
        *param_2 = *param_2 + -1;
        goto LAB_0070b966;
      }
      if (in_AL != 'd') {
        if (in_AL != 'j') {
          return 0;
        }
        iVar2 = in_EDX[7];
        goto joined_r0x0070b8e6;
      }
      if ((0 < in_EDX[3]) && (in_EDX[3] < 0x20)) goto LAB_0070b91f;
      goto LAB_0070b887;
    }
    if ((-1 < in_EDX[4]) && (in_EDX[4] < 0xc)) goto LAB_0070b91f;
  }
  else if (in_AL == 'p') {
    if ((-1 < in_EDX[2]) && (in_EDX[2] < 0x18)) goto LAB_0070baaa;
  }
  else if (in_AL == 'w') {
    if ((-1 < in_EDX[6]) && (in_EDX[6] < 7)) goto LAB_0070b91f;
  }
  else {
    if (in_AL == 'x') {
      if (param_4 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      goto LAB_0070b96a;
    }
    if (in_AL != 'y') {
      if (in_AL != 'z') {
        return 0;
      }
      goto LAB_0070ba01;
    }
    if (-1 < in_EDX[5]) goto LAB_0070b91f;
  }
LAB_0070b9aa:
  puVar3 = (undefined4 *)FUN_006ead5f();
LAB_0070b9af:
  *puVar3 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  return 0;
}

