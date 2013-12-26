
#include "clouds.h"
#include "noise.h"
#include "config.h"
#include "util.h"
#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "matrix.h"
#include "time.h"
#include "craftcommonstructs.h"

void create_clouds() {
    printf("[CLOUDS] Create clouds called\n");
    weather = (Weather*)malloc(sizeof(Weather));
    
    //choose a starting season.
    weather->season = SEASON_SUMMER; //default to summer for now
    weather->season_modifier = SEASON_M_NORMAL; //Normal season
    
    //set a prevailaing wind direction.
    weather->x_prevailing_winds = 0.01f;
    weather->z_prevailing_winds = 0.0f;
    
    //set a lifecycle current and max
    weather->season_lifecycle_current = 0;
    weather->season_lifecycle_max = 10000;
    
    weather->cloud_count = 0;
    weather->clouds = (Cloud**)malloc(MAXIMUM_CLOUDS * sizeof(Cloud*));
    /*
    int points = (6 * 3);
    float dataBuffer[3 * points + 3 * points + 2 * points];
    float *data = &(dataBuffer[0]);
    
    
            2       4
     
     1                      6
     
            3       5
     
     
    
    float small_size_length = 1.0f;
    float old_size_length = small_size_length * 1.5f;
    
    float angleOne =    M_PI/2.0f;
    float angleTwo =    M_PI/4.0f;
    float angleThree =  M_PI/8.0f;
    float angleFour =   M_PI/10.0f;
    
    float ypos = -0.5f;

    *(data++) = small_size_length; *(data++) = ypos; *(data++) = 0;
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 1.0f; *(data++) = 0.5f;
    
    *(data++) = small_size_length * cos(angleOne); *(data++) = ypos; *(data++) = small_size_length * sin(angleOne);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.6f; *(data++) = 0.0f;

    *(data++) = small_size_length * cos(angleTwo); *(data++) = ypos; *(data++) = small_size_length * sin(angleTwo);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.3f; *(data++) = 0.0f;
    
    *(data++) = -small_size_length; *(data++) = ypos; *(data++) = 0;
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.0f; *(data++) = 0.5f;
    
    *(data++) = small_size_length * cos(angleThree); *(data++) = ypos; *(data++) = small_size_length * sin(angleThree);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.6f; *(data++) = 0.0f;
    
    *(data++) = small_size_length * cos(angleFour); *(data++) = ypos; *(data++) = small_size_length * sin(angleFour);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.3f; *(data++) = 0.0f;
    
    
    ypos = 0.0f;
    small_size_length *= 1.5f;
    
    *(data++) = small_size_length; *(data++) = ypos; *(data++) = 0;
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 1.0f; *(data++) = 0.5f;
    
    *(data++) = small_size_length * cos(angleOne); *(data++) = ypos; *(data++) = small_size_length * sin(angleOne);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.6f; *(data++) = 0.0f;
    
    *(data++) = small_size_length * cos(angleTwo); *(data++) = ypos; *(data++) = small_size_length * sin(angleTwo);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.3f; *(data++) = 0.0f;
    
    *(data++) = -small_size_length; *(data++) = ypos; *(data++) = 0;
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.0f; *(data++) = 0.5f;
    
    *(data++) = small_size_length * cos(angleThree); *(data++) = ypos; *(data++) = small_size_length * sin(angleThree);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.6f; *(data++) = 0.0f;
    
    *(data++) = small_size_length * cos(angleFour); *(data++) = ypos; *(data++) = small_size_length * sin(angleFour);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.3f; *(data++) = 0.0f;
    
    
    ypos = 15.5f;
    small_size_length = old_size_length;
    
    *(data++) = small_size_length; *(data++) = ypos; *(data++) = 0;
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 1.0f; *(data++) = 0.5f;
    
    *(data++) = small_size_length * cos(angleOne); *(data++) = ypos; *(data++) = small_size_length * sin(angleOne);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.6f; *(data++) = 0.0f;
    
    *(data++) = small_size_length * cos(angleTwo); *(data++) = ypos; *(data++) = small_size_length * sin(angleTwo);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.3f; *(data++) = 0.0f;
    
    *(data++) = -small_size_length; *(data++) = ypos; *(data++) = 0;
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.0f; *(data++) = 0.5f;
    
    *(data++) = small_size_length * cos(angleThree); *(data++) = ypos; *(data++) = small_size_length * sin(angleThree);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.6f; *(data++) = 0.0f;
    
    *(data++) = small_size_length * cos(angleFour); *(data++) = ypos; *(data++) = small_size_length * sin(angleFour);
    *(data++) = 0; *(data++) = -1.0f; *(data++) = 0;
    *(data++) = 0.3f; *(data++) = 0.0f;
    
    weather->cloud_vertex_buffer = gen_buffer(sizeof(dataBuffer), dataBuffer);
    */
    GLfloat *data = malloc_faces(8, 6);
    make_cube(data, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0.5, 16);
    weather->cloud_vertex_buffer = gen_faces(8, 6, data);
    
    
}




void update_clouds(Player *player) {
    weather->season_lifecycle_current++;
    
    if(weather->season_lifecycle_current > weather->season_lifecycle_max){
        //season change
        weather->season_lifecycle_current = 0;
        weather->season++;
        printf("[CLOUDS] Season changed");
        
        weather->season = weather->season > SEASON_SPRING ? SEASON_SUMMER : weather->season;
    }
    
    //update prevailing winds
    int i;
    for(i=0; i<weather->cloud_count; i++){
        
        Cloud *c = (weather->clouds)[i];
        //delete clouds that have strayed too far from the player, or have degenerated.
        State *s = &player->state;
        if ((pow(s->x - (((weather->clouds)[i])->x),2) + pow(s->z - (((weather->clouds)[i])->z),2)) > pow(300,2)  || c->cloud_life <= 0) {
            
            
            remove_cloud(c);
            weather->clouds[i] = NULL;

            
            int j;
            for (j=i+1; j<weather->cloud_count; j++) {
                weather->clouds[j-1] = weather->clouds[j];
            }
            weather->cloud_count--;
            i--;
        } else {
            
            //individual clouds move with the prevailing wind, and with some slight
            //variation
            c->lifetimelength_subcounter++;
            
            if (c->lifetimelength_subcounter > 2000) {
                c->lifetimelength_subcounter = 0;
                c->cloud_ticks++;
                
                
                if (c->cloud_ticks < c->lifetimelength_subcounter) {
                    int next_state = c->lifetime[c->cloud_ticks];
                    float state_float = next_state/RAND_MAX;
                    
                    if (c->cloud_mode ==  CLOUD_MODE_STABLE) {
                        if (state_float < 0.6) {
                            c->cloud_mode = CLOUD_MODE_STABLE;
                        } else if(state_float < 0.8){
                            if (state_float > 0.78) {
                                c->cloud_mode = CLOUD_MODE_BUILDING_FAST;
                            } else {
                                c->cloud_mode = CLOUD_MODE_BUILDING;
                            }
                        } else if(state_float < 1){
                            if (state_float > 0.98) {
                                c->cloud_mode = CLOUD_MODE_DECAYING_FAST;
                            } else {
                                c->cloud_mode = CLOUD_MODE_DECAYING;
                            }
                        }
                    } else if (c->cloud_mode == CLOUD_MODE_BUILDING || c->cloud_mode ==  CLOUD_MODE_BUILDING_FAST) {
                        if (state_float < 0.4) {
                            c->cloud_mode = CLOUD_MODE_BUILDING;
                        } else if (state_float < 0.6) {
                            c->cloud_mode = CLOUD_MODE_STABLE;
                        } else if (state_float < 0.8) {
                            c->cloud_mode = CLOUD_MODE_BUILDING_FAST;
                        } else if(state_float < 1){
                            if (state_float > 0.98) {
                                c->cloud_mode = CLOUD_MODE_DECAYING_FAST;
                            } else {
                                c->cloud_mode = CLOUD_MODE_DECAYING;
                            }
                        }
                    } else if (c->cloud_mode == CLOUD_MODE_DECAYING || c->cloud_mode ==  CLOUD_MODE_DECAYING_FAST) {
                        if (state_float < 0.2) {
                            c->cloud_mode = CLOUD_MODE_DECAYING;
                        } else if (state_float < 0.7) {
                            c->cloud_mode = CLOUD_MODE_STABLE;
                        } else if (state_float < 0.8) {
                            c->cloud_mode = CLOUD_MODE_DECAYING_FAST;
                        } else if(state_float < 1){
                            if (state_float > 0.98) {
                                c->cloud_mode = CLOUD_MODE_BUILDING_FAST;
                            } else {
                                c->cloud_mode = CLOUD_MODE_BUILDING;
                            }
                        }
                    }
                    
                    
                } else {
                    c->cloud_mode = CLOUD_MODE_DECLINING;
                }
            }
            
            c->x += weather->x_prevailing_winds;
            c->z += weather->z_prevailing_winds;
            
            c->x += ((weather->clouds)[i])->dx;
            c->y += ((weather->clouds)[i])->dy;
            c->z += ((weather->clouds)[i])->dz;
            
            
            if (c->cloud_mode == CLOUD_MODE_BUILDING) {
                c->cloud_life++;
                
                c->sx += 0.01 + (rand() / RAND_MAX) * 0.01;
                c->sy += 0.01 + (rand() / RAND_MAX) * 0.01;
                c->sz += 0.01 + (rand() / RAND_MAX) * 0.01;
                
            } else if (c->cloud_mode == CLOUD_MODE_BUILDING_FAST) {
                c->cloud_life += 2;
                
                c->sx += 0.01 + (rand() / RAND_MAX) * 0.03;
                c->sy += 0.01 + (rand() / RAND_MAX) * 0.03;
                c->sz += 0.01 + (rand() / RAND_MAX) * 0.03;
                
            } else if (c->cloud_mode == CLOUD_MODE_DECAYING) {
                c->cloud_life--;
                c->sx -= 0.01 + (rand() / RAND_MAX) * 0.01;
                c->sy -= 0.01 + (rand() / RAND_MAX) * 0.01;
                c->sz -= 0.01 + (rand() / RAND_MAX) * 0.01;
            } else if (c->cloud_mode == CLOUD_MODE_DECAYING_FAST) {
                c->cloud_life -= 2;
                c->sx -= 0.01 + (rand() / RAND_MAX) * 0.03;
                c->sy -= 0.01 + (rand() / RAND_MAX) * 0.03;
                c->sz -= 0.01 + (rand() / RAND_MAX) * 0.03;
            } else if(c->cloud_mode == CLOUD_MODE_DECLINING){
                
                c->sx -= 0.001 + (rand() / RAND_MAX) * 0.005;
                c->sy -= 0.001 + (rand() / RAND_MAX) * 0.005;
                c->sz -= 0.001 + (rand() / RAND_MAX) * 0.005;
                c->cloud_life = 10000;
            }
            
            if (c->cloud_life <= 0) {
                c->cloud_mode = CLOUD_MODE_DECLINING;
                c->cloud_life = 10000;
            }
            
            if (c->sx < 0 || c->sy < 0 || c->sz < 0) {
                c->cloud_life = 0;
            }
            
            
        }
    }
    
    //add new cloud if required.
    add_cloud(player);
    
}


void add_cloud(Player *player){
    //certain types of weather will force less clouds to be allowed.
    int weather_cloud_max_modifier = 0;
    if(weather->cloud_count < MAXIMUM_CLOUDS - weather_cloud_max_modifier){
        Cloud *c = (Cloud*)malloc(sizeof(Cloud));
        c->lifetimelength = 16 + (rand() % 10);
        c->lifetime = malloc(c->lifetimelength * sizeof(int));
        
        
        c->cloud_ticks = 0;
        c->lifetimelength_subcounter = 0;
        
        c->dx = (rand()/RAND_MAX) * 0.01 - 0.005;
        c->dz = (rand()/RAND_MAX) * 0.01 - 0.005;
        
        //randomly distribute around the player
        State *s = &player->state;
        
        c->x = s->x + (rand() % 400) - 200;
        c->y = s->y + (rand() % 400) - 200;
        c->z = s->z + (rand() % 400) - 200;
        
        c->sx = (rand() % 30) + 1.0f;
        c->sy = (rand() % 4) + 1.0f;
        c->sz = (rand() % 30) + 1.0f;
        
        c->cloud_mode = CLOUD_MODE_STABLE;
        c->cloud_life = 5000;
        
        weather->clouds[weather->cloud_count] = c;
        weather->cloud_count++;
        
        int i;
        for (i=0; i<c->lifetimelength; i++) {
            c->lifetime[i] = rand();
        }

        
        
        printf("[CLOUDS] Added new cloud\n");
    }
}

void render_cloud(Cloud *cloud, Attrib *attrib){
    
    float matrix[16];
    
    float matrix_prev[16];
    glGetUniformfv(attrib->program, attrib->model, matrix_prev);
    glGetUniformfv(attrib->program, attrib->model, matrix);
    
    mat_identity(matrix);
    mat_translate(matrix,cloud->x, 30 + cloud->y, cloud->z);
    
    
    mat_scale(matrix, cloud->sx,cloud->sy,cloud->sz);
    glUniformMatrix4fv(attrib->model, 1, GL_FALSE, matrix);
    
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glUniformMatrix4fv(attrib->model, 1, GL_FALSE, matrix_prev);
}

void render_clouds(Attrib *attrib,int width, int height, Player *player, float fov, int ortho) {
    int i;

    State *s = &player->state;

    float matrix[16];
    set_matrix_3d( matrix, width, height, s->x, s->y, s->z, s->rx, s->ry, fov, ortho);
    glUseProgram(attrib->program);
    glUniformMatrix4fv(attrib->matrix, 1, GL_FALSE, matrix);
    glUniform3f(attrib->camera, s->x, s->y, s->z);
    glUniform1i(attrib->sampler, 0);
    glUniform1f(attrib->timer, glfwGetTime());
    
    
    
    glBindBuffer(GL_ARRAY_BUFFER, weather->cloud_vertex_buffer);
    glEnableVertexAttribArray(attrib->position);
    glEnableVertexAttribArray(attrib->normal);
    glEnableVertexAttribArray(attrib->uv);
    glVertexAttribPointer(attrib->position, 3, GL_FLOAT, GL_FALSE,
                          sizeof(GLfloat) * 8, 0);
    glVertexAttribPointer(attrib->normal, 3, GL_FLOAT, GL_FALSE,
                          sizeof(GLfloat) * 8, (GLvoid *)(sizeof(GLfloat) * 3));
    glVertexAttribPointer(attrib->uv, 2, GL_FLOAT, GL_FALSE,
                          sizeof(GLfloat) * 8, (GLvoid *)(sizeof(GLfloat) * 6));
    
    for(i=0; i<weather->cloud_count; i++){
        render_cloud((weather->clouds)[i], attrib);
    }
    

    glDisableVertexAttribArray(attrib->position);
    glDisableVertexAttribArray(attrib->normal);
    glDisableVertexAttribArray(attrib->uv);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    //glUniformMatrix4fv(attrib->matrix, 1, GL_FALSE, matrix_prev);
}

void remove_cloud(Cloud *c){
    free(c->lifetime);
    free(c);
    printf("[CLOUDS] Remove cloud called\n");
}

void cleanup_clouds() {
    printf("[CLOUDS] Cleanup clouds called\n");
    printf("[CLOUDS] Removing %d clouds.\n",weather->cloud_count);
    int i;
    for(i=0; i<weather->cloud_count; i++){
        remove_cloud((weather->clouds)[i]);
    }
    free(weather->clouds);
    
    free(weather);
}
