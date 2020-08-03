#include<stdio.h>
#include<string.h>
void main()
{
    printf("\t\t\t\tWORKING WITH EMAILS\n");
    printf("Description:-\n*Can send mails to different accounts\n*Delete mails\n*Check Mails\n");
    int i,j=0,n,m,f=0;
    char s[50],s1[50],s2[50],s3[50][10],ch;
    FILE *p,*t;
    l3:printf("1)Log In\n2)Sign Up\n");
    scanf("%d",&n);
    if(n==1)
    {
        l1:printf("Enter email id:");
        scanf("%s",s);
        scanf("%*c");
        f=0;
        p=fopen("Accounts.txt","r");
        fseek(p,0,0);
        for(i=0;i>=0;i++)
        {
            fscanf(p,"%s",s1);
            n=strcmp(s,s1);
            if(n==0)
            {
                f=1;
                break;
            }
            ch=fgetc(p);
            if(ch==EOF)
            {
                break;
            }
            fseek(p,-1,1);
        }
        if(!f)
        {
            printf("Please Enter correct Email or try Signing Up\n\n");
            goto l1;
        }
        fscanf(p,"%s",s2);
        l2:printf("Enter password:");
        scanf("%[^\n]s",s);
        scanf("%*c");
        n=strcmp(s,s2);
        if(n==0)
        {
            printf("Sucessfully Logged In!\n");
        }
        else
        {
            printf("Invalid Password\n\n");
            goto l2;
        }
        fclose(p);
    }
    else
    {
        p=fopen("Accounts.txt","r");
        l4:printf("Enter email id:");
        scanf("%s",s);
        scanf("%*c");
        fseek(p,0,0);
        for(i=0;i>=0;i++)
        {
            fscanf(p,"%s",s1);
            n=strcmp(s,s1);
            if(n==0 && i%2==0)
            {
                printf("Already Registered\n\n");
                goto l4;
                break;
            }
            ch=fgetc(p);
            if(ch==EOF)
            {
                break;
            }
            fseek(p,-1,1);
        }
        fclose(p);
        p=fopen("Accounts.txt","a");
        fprintf(p,"%s\n",s);
        printf("Enter password:");
        scanf("%[^\n]s",s1);
        fprintf(p,"%s\n",s1);
        printf("Account Sucessfully Created!\n\n");
        fclose(p);
        goto l3;
    }
    f=0;
    l5:printf("Enter your choice:\n1)Send Email\n2)Check Inbox\n3)Clear Inbox\n4)Log Out\n)");
    scanf("%d",&n);
    if(n==1)
    {
        p=fopen("Accounts.txt","r");
     l6:printf("To:");
        scanf("%s",s);
        scanf("%*c");
        fseek(p,0,0);
        for(i=0;i>=0;i++)
        {
            fscanf(p,"%s",s2);
            n=strcmp(s,s2);
            if(n==0 && i%2==0)
            {
                f=1;
                fclose(p);
                p=fopen("Inbox.txt","a");
                fprintf(p,"%s",s);
                fprintf(p,"\nFrom:%s\n",s1);
                printf("Enter the body:\n");
                printf("(Press enter while done)\n");
                scanf("%[^\n]s",s);
                scanf("%*c");
                fprintf(p,"%s\n",s);
                printf("Email Sent\n\n");
                fclose(p);
                goto l5;
                break;
            }
            ch=fgetc(p);
            if(ch==EOF)
            {
                break;
            }
            fseek(p,-1,1);
        }
        if(!f)
        {
            printf("Invalid Email ID\n\n");
            goto l6;
        }
    }
    else if(n==2)
    {
        f=0;
        p=fopen("Inbox.txt","r");
        fseek(p,0,0);
        for(i=0;i>=0;i++)
        {
            ch=fgetc(p);
            if(ch==EOF)
            {
                break;
            }
            fseek(p,-1,1);
            fscanf(p,"%s",s);
            n=strcmp(s,s1);
            if(n==0)
            {
                f=1;
                fscanf(p,"%s",s2);
                printf("%s\n",s2);
                fscanf(p,"%*c");
                fscanf(p,"%[^\n]s",s2);
                printf("%s\n",s2);
            }
        }
        if(f==1)
        {
            printf("1)Reply\n2)Ignore\n");
            scanf("%d",&n);
            if(n==1)
            {
                goto l6;
            }
        }
        if(!f)
        {
            printf("No Messages\n\n");
        }
        fclose(p);
        goto l5;

    }
    else if(n==3)
    {
        f=0;
        p=fopen("Inbox.txt","a");
        fprintf(p,"#");
        fclose(p);
        p=fopen("Inbox.txt","r");
        fseek(p,0,0);
        fscanf(p,"%[^#]s",s2);
        for(i=0;s1[i]!='\0';i++)
        {
            for(j=0;s2[j]!='\0';j++)
            {
                if(s1[i]==s2[j])
                {
                        for(;s1[i]!='\0';)
                        {
                            i++;
                            j++;
                            if(s1[i]==s2[j])
                            {
                                if(s1[i]=='\0')
                                {
                                    s2[j-1]='&';
                                    f=1;
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                }
                if(f==1)
                {
                    break;
                }
            }
            if(f==1)
            {
                break;
            }
        }
        fprintf(p,"%s",s2);
        fclose(p);
        p=fopen("Inbox.txt","w");
        fprintf(p,"%s",s2);
        printf("Successfully Cleared\n\n");
        fclose(p);
        goto l5;
    }
    else if(n==4)
    {
        fclose(p);
        printf("Succesfully Logged Out\n\n");
        goto l3;
    }

}


